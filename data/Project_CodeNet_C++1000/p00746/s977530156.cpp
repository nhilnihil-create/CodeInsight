#include <iostream>
#include <vector>
#include <algorithm>
#include<string.h>
using namespace std;
typedef pair<int,int>pa;
vector<pa>vec;
int main(){
    while(true){
        int N,n,d,l=0,r=1,t=1,b=0,x,y;
        cin>>N;
        if(N==0)break;
        vec.push_back(pa(0,0));
        while(--N){
            cin>>n>>d;
            pa p=vec[n];
            x=p.first,y=p.second;
            switch(d){
                case 0:
                    l=min(l,x-1);vec.push_back(pa(x-1,y));
                    break;
                case 1:
                    b=min(b,y-1);vec.push_back(pa(x,y-1));
                    break;
                case 2:
                    r=max(r,x+2);vec.push_back(pa(x+1,y));
                    break;
                case 3:
                    t=max(t,y+2);vec.push_back(pa(x,y+1));
                    break;
                default:break;
            }
        }
        cout<<r-l<<" "<<t-b<<endl;
        vec.clear();
    }
    return 0;
}
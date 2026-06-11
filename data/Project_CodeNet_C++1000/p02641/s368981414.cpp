#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int x,n;
    cin >> x >> n;
    
    if(n==0){
        cout << x << endl;
        return 0;
    }
    
    map<int,int> p;
    int i;
    for(i=0;i<=101;i++) p[i]=i;
    int q;
    for(i=0;i<n;i++){
        cin >> q;
        p.erase(q);           
    }

    int a=0,u=x,o=101-x,b=101;
    for(i=0;i<=101;i++){
        if(p.count(i)){
            if(i<=x){
                if(u>x-p.at(i)){
                    u = x-p.at(i);
                    a = p.at(i);
                }
            }
            if(i>x){
                if(o>p.at(i)-x){
                    o = p.at(i)-x;
                    b = p.at(i);
                }
            }
        }else{
            continue;
        }
    }

    if(u<=o){
        cout << a << endl;
    }else{
        cout << b << endl;
    }

}

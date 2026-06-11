#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    vector<int>p(100);
    vector<int>q(101);
    for(int i=0;i<n;i++){
        cin>>p[i];
        q[p[i]]++;
    }
    for(int i=0;i<1000;i++){
        if(q[x-i]==0){
            cout<<x-i<<endl;
            break;
        }
        if(q[x+i]==0){
            cout<<x+i<<endl;
            break;
        }
    }
}

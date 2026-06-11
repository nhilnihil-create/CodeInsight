#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    int a,b;cin>>a>>b;
    int max =10000;
    for(int i = 0;i<max;i++){
        int x8 = i*0.08;
        int x10 = i*0.1;

        if(a==x8&&b==x10){
            cout<<i<<endl;
            return 0;
        }

    }
    cout<<-1<<endl;

}

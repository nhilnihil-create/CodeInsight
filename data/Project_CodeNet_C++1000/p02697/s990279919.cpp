#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,m;
    cin>>n>>m;
    if(n%2==1){
        int a=(n-1)/2;
        int b=a+1;
        rep(i,m){
            cout<<a<<" "<<b<<endl;
            a--;
            b++;
        }
        return 0;
    }
    else{
        int a=n/2-1;
        int b=a+1;
        rep(i,m){
            if((b-a)*2<n){
                cout<<a<<" "<<b<<endl;
            }
            else{
                cout<<a<<" "<<b+1<<endl;
            }
            a--;
            b++;
        }
        return 0;
    }
}

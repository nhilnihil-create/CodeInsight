#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
 
    void solve(){
        int n,m;
        cin>>n>>m;
        vector<int>vis(n,0);
        int acc=0,pen=0;
        vector<int>s(n,0);
        for(int i=0;i<m;i++){
            int num;
            cin>>num;
            --num;
            string str;
            cin>>str;
            if(str=="WA"){
                if(vis[num]==0)
                    s[num]++;
            }   
            else{
                if(vis[num]==0){
                    vis[num]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]){
                acc++;
                pen+=s[i];
            }
        }
        cout<<acc<<" "<<pen;
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }
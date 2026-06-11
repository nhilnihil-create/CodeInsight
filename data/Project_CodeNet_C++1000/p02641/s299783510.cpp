
/*
	*	Created By: 'Present_Sir'
	*	Created On: Thursday 27 August 2020 02:48:15 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define lgt(s) ((int)s.length())
#define int long long
using namespace std;

class Solver{
    public:
        void test(){
            //int t; cin>>t; for(int i=1; i<=t; ++i)
            {
                //cout<<"Case #"<<i<<": ";
                this->solve();
            }
        }
        void solve(){
            int x,n;
            cin>>x>>n;
            if(n == 0){
                cout<<x<<endl;
                return;
            }
            if(n == 1){
                int t;
                cin>>t;
                if(t == x){
                    cout<<x-1<<endl;
                }else{
                    cout<<x<<endl;
                }
                return;
            }
            multiset < int > s;
            for(int i=0; i<n; ++i){
                int p;
                cin>>p;
                s.insert(p);
            }
            //cout<<x<<endl;
            int lx=x, rx=x;
            auto t = s.find(x);
            if(t == s.end()){
                cout<<x<<endl;
                //cout<<"Kyu?"<<endl;
            }else{
                while(s.find(rx)!=s.end()){
                    ++rx;
                }
                while(s.find(lx)!=s.end()){
                    --lx;
                }
                //cout<<lx<<" "<<rx<<endl;
                if(x-lx == rx-x){
                    cout<<lx<<endl;
                }else{
                    if(x-lx < rx-x){
                        cout<<lx<<endl;
                    }else{
                        cout<<rx<<endl;
                    }
                }
            }
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}


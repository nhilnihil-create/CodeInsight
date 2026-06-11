#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
long double eps = 1e-6;
long double pi = acos(-1);


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    n = (1<<n);
    multiset<int> st;
    multiset<int,greater<int>> used;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.insert(a);
    }
    auto it = st.end(); it--;
    used.insert(*it);
    st.erase(it,st.end());
    while(st.size()){
        vector<int> v;
        for(auto i:used){
            auto it = st.lower_bound(i);
            if(it == st.begin()){
                cout << "No\n";
                return 0;
            }
            auto nx = it;
            it--;
            v.push_back(*it);
            st.erase(it,nx);
        }
        for(auto i:v)used.insert(i);
 
    }
    cout << "Yes\n";
}
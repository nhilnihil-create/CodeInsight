#include <bits/stdc++.h>

    using namespace std;
    template <typename T>
    void debug(string t, T input) {
        cout<<t<<"-> "<<input<<"\n";
    }
    template <typename T>
    void debug(int i,string t, T input) {
        cout<<"Case#"<<i<<" "<<t<<"-> "<<input<<"\n";
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n,k,c;
        cin>>n>>k>>c;
        string s;
        cin>>s;
        vector<int>a,b;
        for(int i=0;i<n;i++){
            if(s[i]=='o'){
                a.push_back(i);
                i+=c;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='o'){
                b.push_back(i);
                i-=c;
            }
        }
        for(int i=0;i<k;i++){
            if(a[i]==b[k-i-1])
                cout<<a[i]+1<<"\n";
        }
        return 0;
    }

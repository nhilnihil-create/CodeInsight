#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;

int main() {
    int n;cin>>n;
    int si=to_string(n).size();
    if(si==1){
        cout<<n<<endl;
    }else{
        map<P,int> num;
        for(int i=1;i<=n;i++){
            int fst;
            string s=to_string(i);
            fst=s[0]-'0';
            int last=i%10;
            if(num.count(make_pair(fst,last))){
                num.at(make_pair(fst,last))++;
            }else{
                num[make_pair(fst,last)]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                if(num.count(make_pair(i,j))){
                    if(num.count(make_pair(j,i))){
                        ans+=num.at(make_pair(i,j))*num.at(make_pair(j,i));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
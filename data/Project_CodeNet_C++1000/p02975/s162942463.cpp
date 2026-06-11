# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,x;
unordered_set<int>SET;
unordered_map<int,int>byk;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        SET.insert(x);
        byk[x]++;
    
    }
    if(SET.size()==1 && SET.count(0)!=0){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(n%3==0){
        if(SET.size()==2){
            if(byk[0]==n/3){
                cout<<"Yes"<<endl;
                return 0;
            }

        }
        else if(SET.size()==3){
            int bil=0;
            for(auto isi : SET){
                bil^=isi;
            }
            if(bil!=0){
                cout<<"No"<<endl;
                return 0;
            }
            int banyak=n/3;
            int cnt=0;
            for(auto isi:SET){
                if(byk[isi]==banyak) cnt++;
            }
            if(cnt==3){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;
}
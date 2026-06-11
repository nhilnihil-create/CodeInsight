#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP2(i,m,n) for(int i=m;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int change(string time){
    int num = (int(time[0]) -48)*100000+(int(time[1]) -48)*10000 +(int(time[3]) -48)*1000+(int(time[4]) -48)*100 + (int(time[6]) -48)*10 + (int(time[7]) -48);

    return num;
}

int main(){
    
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        // cout<<"n"<<n<<endl;
        vector<pair<int,int> > a;
        int ans=0;
        REP(i,n){
            string tmp1,tmp2;
            cin >> tmp1>>tmp2;
            pair<int,int> tmp={change(tmp1),change(tmp2)};
            // ASC2 48~57は数字
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        // REP(i,n){
        //     cout<<a[i].first<<" "<<a[i].second<<endl;
        // }
        
        vector<pair<int,int> > b;
        REP(i,n){
            bool flag = true;
            pair<int,int> tmp3= a[i];
            REP(j,b.size()){
                if(b[j].second <= tmp3.first) {
                    flag = false;
                    b[j]=tmp3;
                    break;
                }
                
            }

            if(flag){
                b.push_back(tmp3);
                ans++;
            }
        }
        
        cout<<ans<<endl;

       
    }

    
}

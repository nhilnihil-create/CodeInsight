#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    int N;cin>>N;
    multiset<int> MS;
    vector<int> A((1<<N));
    for(int i=0;i<(1<<N);i++){
        cin>>A[i];
    }
    
    sort(all(A));
    
    for(int i=0;i<(1<<N)-1;i++){
        MS.insert(-A[i]);
    }
    
    bool ok=true;
    
    vector<int> B;
    B.push_back(A[A.size()-1]);
    
    int kai=1;
    
    for(int k=0;k<N;k++){
        for(int i=0;i<kai;i++){
            auto it=MS.upper_bound(-B[i]);
            if(it==MS.end()){
                ok=false;
            }else{
                MS.erase(it);
                B.push_back(-(*it));
            }
        }
        if(!ok) break;
        kai*=2;
        sort(all(B));
        reverse(all(B));
    }
    
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}


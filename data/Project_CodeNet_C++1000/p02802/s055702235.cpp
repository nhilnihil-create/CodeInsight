#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    
    int N,M,P,num_wa=0,num_ac=0; cin >> N >> M;
    string S;
    int num[N];
    map<int,string> mp{};
    for(int i=0;i<N;i++) num[i] = 0;
    
    for(int i=0;i<M;i++){
        cin >> P >> S;
        if(mp.count(P) == 0){mp[P] = S; if(S == "WA"){num[P-1]++;}else if(S == "AC"){num_ac++;}}
        else if(mp[P] == "WA" && S == "AC"){mp[P] = S; num_ac++; num_wa+=num[P-1];}
        else if( mp[P] == "WA" && S == "WA"){num[P-1]++;}
    }
   cout << num_ac << " " << num_wa << endl;
}
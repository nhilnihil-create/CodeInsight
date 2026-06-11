#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin>> N >> M;


    vector<string> S(N+1, "TLE");
    int ac_cnt = 0;
    int wa_cnt = 0;
    vector<int> WA(N+1, 0);
    for(int i=0; i<M; i++){
        int p;
        string s;
        cin>>p;
        cin>>s;
        
        if(S[p] == "AC"){continue;}
            if(s == "AC"){
                S[p] = "AC";
                ac_cnt++;
                wa_cnt += WA[p];
            }else if(s == "WA"){ 
                S[p] = "WA";
                WA[p]++;
            }
        
    }

    cout<<ac_cnt<<" "<<wa_cnt<<endl;
    return 0;
}
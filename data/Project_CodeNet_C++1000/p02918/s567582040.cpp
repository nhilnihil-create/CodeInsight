#include<bits/stdc++.h>
using namespace std;

int N, K;
string S;
int ser_n = 0;  //1以上の文字連続の塊数
int ini_happi = 0;  //初期幸福人数
int res;

int main(){
    cin >> N >> K;
    cin >> S;

    int i = 0;
    while(i < S.size()){
        int j = 0;
        while(i+j < S.size() && S[i] == S[i+j]) ++j;
        ++ser_n;
        ini_happi += (j-1);
      	i += j;
    }

    if(ser_n & 1)
      res=ini_happi+2*min(ser_n/2,K);
    else
      res=ini_happi+2*min(ser_n/2-1,K)+min(1,max(K-(ser_n/2-1),0));
  
    cout << res << endl;
    return 0;
}

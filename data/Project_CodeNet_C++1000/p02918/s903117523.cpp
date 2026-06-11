#include <bits/stdc++.h>
using namespace std;
 
int main(void) 
{
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;

    string S1="";
  
  
    int same=0,diff=0;
    for(int i=0; i<N-1; i++)
    {
        if(S[i]==S[i+1]) same++;
        if(S[i]!=S[i+1]) diff++;
    }
    //cout << same << " " << diff << endl;

    int ans = 0;
    cout << same + min(K*2,diff) << endl;

    return 0;
}

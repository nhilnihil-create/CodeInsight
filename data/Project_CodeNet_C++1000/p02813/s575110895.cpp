#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,c=1,a,b,ans;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    vector<int> dec(N);

    for(int i=0;i<N;i++)
        cin >> P.at(i);
    for(int i=0;i<N;i++)
        cin >> Q.at(i);
    dec = P;
    sort(dec.begin(),dec.end());

    do{
        if(dec==P)
            a=c;
        if(dec==Q)
            b=c;
        c++;
    }while(next_permutation(dec.begin(), dec.end()));
    ans = abs(a-b);
    cout << ans <<endl;
    
}
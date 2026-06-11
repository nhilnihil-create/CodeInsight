#include <bits/stdc++.h>
using namespace std;

int main(){

    int N,L;
    cin >> N >> L;

    vector<int> v(N);
    for(int i=0;i<N;i++){
        v[i]=L+i;
    }

    int m=100000;
    int t;

    for (size_t i = 0; i < N; i++)
    {
        if(m>abs(v[i])){
            m=abs(v[i]);
            t=i;
        }
    }

    
    int sum = accumulate(v.begin(),v.end(),0)-v[t];
    cout << sum << endl;

    return 0;
}
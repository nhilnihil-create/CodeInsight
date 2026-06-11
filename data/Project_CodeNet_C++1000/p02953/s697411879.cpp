#include <bits/stdc++.h>

using namespace std;

long long n,k,current,answer,i;

int main()
{
    cin >> n;
    cin >> current;
    current--;
    answer = 1;
    for(i=2; i<=n; i++) {
        cin >> k;
        if(k>current) k--;
        if(k<current) {
            answer = 0;
            break;
        }
        current = k;
    }
    if(answer == 1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}

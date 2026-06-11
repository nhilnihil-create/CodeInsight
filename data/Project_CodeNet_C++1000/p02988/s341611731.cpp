#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,cnt=0;
    cin >> n;

    vector<int> p(n);
    for(i=0; i<n; i++)
        cin >> p.at(i);

    for(i=1; i<n-1; i++){
        if(p.at(i) > p.at(i-1) && p.at(i) < p.at(i+1))
            cnt++;
        else if(p.at(i) < p.at(i-1) && p.at(i) > p.at(i+1))
            cnt++;
        
    }

    cout << cnt << endl;
}
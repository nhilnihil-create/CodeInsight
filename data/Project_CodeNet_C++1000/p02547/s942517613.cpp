#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<bool> vect;

    for(int i = 0 ; i < N ; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	vect.push_back(a == b);
    }

    bool flag = false;

    for(int i = 0 ; i < N-2 ; i++)
    {
    	if(vect[i] && vect[i+1] && vect[i+2])flag = true;
    }

    if(flag)cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}
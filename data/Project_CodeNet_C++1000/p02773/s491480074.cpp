#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio( false ); 
    cin.tie( NULL );


    int n;
    cin >> n;

    map <string, int> S;
    int maior = 1;

    for (int i = 0; i < n; ++i)
    {
    	string s;
    	cin >> s;

    	if(S.find(s) == S.end()) {
    		S[s] = 1;
       	}
    	else {
    		S[s]++;

    		maior = max(maior, S.find(s) -> second);
    	}
    }

    for (auto it = S.begin(); it != S.end(); ++it)
    {
    	if(it -> second == maior)
    	{
    		cout << it -> first << endl;
    		// cout << " " << it -> second << endl;
    	}
    }

    return 0;
}
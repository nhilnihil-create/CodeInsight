#include <bits/stdc++.h>
#include <vector>

#define fo(i, t) for(int i = 0; i < t; i++)
#define rfo(i, t) for(int i = n - 1; i > 0; i--)
#define pb push_back

/*typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<vector<int>> mi;*/

using namespace std;

int main()
{
	int t = 1;
	cin >> t;
    int tempa;
    int tempb;
    string result = "No";
    int count = 0;
    int mx = 0;
    for(int i = 0; i < t; i++)
	{
       cin >> tempa;
       cin >> tempb;
       if(tempa == tempb)
       {
       count += 1;
       mx = max(mx, count);
       }
       else
       {
           count  = 0;
       }
    }
    if(mx > 2)
        cout << "Yes";
    else
    {
        cout << "No";
    }
    
}

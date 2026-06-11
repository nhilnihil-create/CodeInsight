#include <bits/stdc++.h>

using namespace std;


void Main()
{
    string S;
    cin >> S;

    if (S[2] == S[3] && S[4] == S[5]) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
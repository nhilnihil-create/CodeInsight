#include <bits/stdc++.h>
#define ll long long
#define Arman_Sykot ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
using namespace std;

int main()
{
/*********************/
// Author:
        Arman_Sykot;
/*********************/
    
	int count = 0, max = 0;
    string s;
    cin >> s;
 
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'R') {
            while (s[i] == 'R') {
                count++;
                i++;
            }
        }
 
        if (count > max) {
            max = count;
            count = 0;
        }
    }
 
    cout << max << endl;
 
	
	return 0;
} 


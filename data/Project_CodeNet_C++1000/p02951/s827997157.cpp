#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; 
    cin >> a >> b >> c;

    if (a == b)
    	cout << c;
    else if (c + b >= a){
    	while (b != a) {
    		c--;
    		b++;
    	}
    	cout << c;
    }
    else if (c + b < a)
    	cout << 0;
    else 
    	cout << c;

    


    return 0;
}

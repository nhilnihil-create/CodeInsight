#include <bits/stdc++.h>
#include <string.h>
#define ll long long

using namespace std;

int main() {
	
	int a,b,c;
	cin >> a >> b >> c;
    int k;
    cin >> k;
    int count = 0;
    while(a >= b)
    {
        b = b*2;
        count+=1;
        if(count >= k)
        {
            
            break;
        }
    }
    if(count < k)
    while(b >= c)
    {
        c = c*2;
        count+= 1;
        if(count >= k)
        {
            break;
        }
    }
    if((a < b) && (b < c) && (count <= k))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
	return 0;
}

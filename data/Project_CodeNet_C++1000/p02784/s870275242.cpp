#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, sum = 0;
    cin >> a >> b;
    int ara[b];
    for(int i = 0 ; i < b ; i++) cin >> ara[i];
    for(int i = 0 ; i < b ; i++){
        sum += ara[i];
    }
    if(sum >= a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;





	return 0;
}

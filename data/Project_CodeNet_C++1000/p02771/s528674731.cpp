#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && a != c)
        cout << "Yes";
    else if(a == c && b != c)
        cout << "Yes";
    else if(b == c && a != b)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

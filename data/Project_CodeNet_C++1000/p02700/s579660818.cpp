#include<bits/stdc++.h>
using namespace std;
int A, B, C, D;
int main()
{
    cin >> A >> B >> C >> D;

    int t = C/B + (C%B>0);
    int s = A/D + (A%D>0);
    if(t<=s)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    //cout << s << " " << t << endl;
    return 0;
}

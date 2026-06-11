#include <bits/stdc++.h>
using namespace std;

int main()
{
    
int P,Q,R;
cin >> P >> Q >> R ;

cout << min ({(P+Q), (P+R),(Q+P),(Q+R),(R+P),(R+Q)})<< endl;    

}
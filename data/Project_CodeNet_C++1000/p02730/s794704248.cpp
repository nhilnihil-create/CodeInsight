#include <bits/stdc++.h>

using namespace std;

#define lli  long long int
#define pb   push_back

int main(){
    string s;
    int n, flag =0;
    cin >> s;
    n = s.size()-1;

    for(int i=0; i<=n/4; i++){
        //cout << s[i] << " " << s[n-i] << " " << s[((n-2)/2)-i] << " " << s[((n+2)/2)+i] << endl;
        if(s[i]==s[n-i] && s[i]==s[((n-2)/2)-i] && s[n-i]==s[((n+2)/2)+i]) flag =1;

        else{
            flag = 0;
            break;
        }

    }
    if (flag == 1) cout << "Yes";
    else cout << "No";
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    string s;
    cin >> s;
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++ ){
            if(s[i] == s[j]){
                c++;
            }
        }
    }
    if(c == 2){
        cout << "Yes";
    }
    else{
        cout << "No";
    }


}





///promy_pompom
//hello world

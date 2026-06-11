using namespace std;
#include <bits/stdc++.h>

int main()
{
    int a,c=0;cin>>a;
    string s;cin>>s;
    for(int i=0;i<a;i++){
        if(s[i]=='A'){
            if(s[i+1]=='B'){
                if(s[i+2]=='C'){
                    c++;
                }
            }
        }
    }
    std::cout << c << std::endl;
}

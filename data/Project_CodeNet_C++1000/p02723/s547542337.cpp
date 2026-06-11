using namespace std;
#include <bits/stdc++.h>

int main()
{
    string s;cin>>s;
    if(s[2]==s[3]){
        if(s[4]==s[5]){
            std::cout << "Yes" << std::endl;
        }
        else{
            std::cout << "No" << std::endl;
        }
    }
    else{
        std::cout << "No" << std::endl;
    }
}
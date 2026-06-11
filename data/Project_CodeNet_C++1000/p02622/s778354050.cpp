#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define ll long long

using namespace std;


void solve(){
    string str1, str2;
    cin >> str1 >> str2;
    int count = 0;
    for(int i = 0; i < str2.length(); i++)
    {
        if(str1[i]!=str2[i])
        count++;
    }
    cout << count << endl;
  
}

int main()
{
    solve();
    return 0;
}
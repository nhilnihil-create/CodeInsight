#include<vector>
#include<iostream>
#include<algorithm>
#include<chrono>
#include<set>
#include<cstdio>
#include<string>
#include<unordered_map>

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<int> re(n);
    int acc = 0;
    for(int i = 0; i < n; i++)
    { 
        scanf("%d",&re[i]);
        acc ^= re[i];
    }
    for(int i = 0; i < n; i++){
        ans[i] = acc ^ re[i];
    }
    for(auto&& item:ans) 
      cout << item << endl;
}

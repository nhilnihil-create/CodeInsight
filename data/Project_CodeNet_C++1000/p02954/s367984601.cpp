#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
	
    string s; 
    cin >> s; 
    int n = s.size() ; 
    vector<int> ans(n) ; 
    for(int i = 0 ; i < s.size() - 1; ++i) {
        if(s[i] == 'R' && s[i+1] == 'L') {
            int j = i ; 
            while(j>= 0 && s[j] == 'R') {
                if((i-j)%2 ==0)
                    ans[i]++;
                else {
                    ans[i+1]++ ; 
                }
                j--;
            }

            j = i + 1; 
            while(j < s.size() && s[j] =='L'){
                if((j-i)%2==0)
                    ans[i]++ ; 
                else 
                    ans[i+1]++;
                    j++;
            }
       }
    }
    for(int x : ans)cout << x << " " ; 
	
    return 0;
}

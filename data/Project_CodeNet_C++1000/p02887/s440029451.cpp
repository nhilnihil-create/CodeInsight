#include<iostream>
#include<iomanip>
#include<stack>

using namespace std;
typedef long long int ll;



int main()
{
     stack<char> st;
     string s;
     int n;
     cin >> n;
     cin >> s;
     st.push(s[0]);
     for(ll i=1; i< n; i++)
     {
         if(st.top()==s[i]) continue;
         st.push(s[i]);
     }
     cout << st.size();

}

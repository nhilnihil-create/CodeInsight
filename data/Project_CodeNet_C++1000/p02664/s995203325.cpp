        #include<bits/stdc++.h>
         
        using namespace std;
         
         
        int main() {
            string s;
        	ios_base::sync_with_stdio(0);
        	cin >> s;
        	for (int i = 0; i < (int) s.size(); i++)
        		s[i] = (s[i] == '?' ? 'D' : s[i]);
        	cout << s << "\n";
        	return 0;
        }
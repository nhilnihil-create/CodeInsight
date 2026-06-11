#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main(){
    int n , k , c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> L,R;
    for(int i = 0; i < n && L.size() < k;){
        if(s[i]=='o'){
            L.push_back(i);
            i += c+1;
        }else{
            i++;
        }
    }
    for(int j = n-1; j > -1 && R.size() < k;){
        if(s[j]=='o'){
            R.push_back(j);
            j -= c+1;
        }else{
            j--;
        }
    }
    reverse(R.begin(),R.end());
    
    for(int i=0; i<k ; i++){
        if(L[i]==R[i])cout << L[i]+1 << endl;
    }
	return 0;
}

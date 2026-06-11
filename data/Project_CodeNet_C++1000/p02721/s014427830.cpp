#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <map>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    
    vector<int> vec;
    vector<int> vec1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'o'){
        vec.push_back(i+1);
        i += c ;
       
        }
       
    }
    
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == 'o'){
        vec1.push_back(i+1);
        i -= c ;
       
        }
       
    }
    
    for(int i = 0; i< k; i++){
        if(vec[i] == vec1[k - i -1]){
            cout << vec[i] <<'\n';
        }
    }
}








#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<string>> problem_array(n,vector<string>(0));
    for(int i=0;i<m;i++){
        int num;
        string res;
        cin >> num >> res;
        problem_array.at(num-1).push_back(res);
    }
    long long penalty=0,correct=0;
    for(int i=0;i<n;i++){
        int p = 0;
        vector<string> arr = problem_array.at(i);
        
        for(long long j=0;j<arr.size();j++){
            if(arr.at(j) == "WA"){
                p++;
            }else if(arr.at(j) == "AC"){
                correct++;
                penalty += p;
                break;
            }
        }
    }
    cout << correct << " " << penalty << endl;


}
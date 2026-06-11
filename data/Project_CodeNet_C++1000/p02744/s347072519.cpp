#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    pair<string,int> p("a",1);
    vector<pair<string,int>>  a = {p};
    vector<string> A = {"a","b","c","d","e","f","g","h","i","j"};
    
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if(i == n-1){
            for (int j = 0; j < a.size(); j++)
            {
                string s = a[j].first;
                printf("%s\n", s.c_str());
            }
        }
        else{
            int ss = a.size();
            for (int j = 0; j < ss; j++)
            {
                for (int k = 0; k < a[j].second+1; k++)
                {
                    string str = a[j].first + A[k];
                    if(k == a[j].second) a.push_back(make_pair(str,a[j].second+1));
                    else a.push_back(make_pair(str,a[j].second));
                }
                
            }
            a.erase(a.begin(),a.begin()+ss);
        }
    }
    
}

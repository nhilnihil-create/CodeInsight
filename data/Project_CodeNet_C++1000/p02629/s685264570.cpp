#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long int n;cin>>n;
    vector<char> name;
    while(n!=0){
        n--;
        char c=n%26+'a';
        name.push_back(c);
        n/=26;
    }
    for(int i=name.size()-1;i>=0;i--){
        cout<<name[i];
    }
    cout<<endl;
}
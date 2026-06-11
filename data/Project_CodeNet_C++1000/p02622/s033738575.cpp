#include <iostream>
using namespace std;
int main(){
    char s[200001],t[200001];
    cin>>s>>t;
    int i = 0, sum = 0;
    while(s[i]!='\0'){
        if(s[i]!=t[i])
            sum++;
        i++;
    }
    cout<<sum;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    cin>>word;
    
    int len=word.length();
    if(word[len-1] == 's') word=word+"es";
    else word=word+"s";
    cout<<word;
     
 
    
}
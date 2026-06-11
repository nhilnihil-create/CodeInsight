#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <iostream> 
#include <algorithm>
#include <math.h>
#include <map>  
#include <string.h> 
#include <string> 
#include <cctype> 

using namespace std;

int counter[10000];

int main(){	
  
string s="abcdefghijklmnopqrstuvwxyz";
  
char ch;

while (cin>>ch){
  
    if(islower(ch)||isupper(ch)){
  
    ch=tolower(ch);
  
    int num=ch-'a';
  
    counter[num]++;
    
    }
    
}
  
for(int i=0; i<26; i++){
  cout<<s[i]<<' '<<':'<<' '<<counter[i]<<endl;
  }
   

}
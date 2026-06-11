#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <vector>
#include<valarray>
#include<map>
#include <utility>
#include <deque>
#include <queue>
using namespace std;

int main()
{
    long long N;
    cin>>N;
    string s;
    char arr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int count=0;
    while(true){

        if(N<26){


            break;
        }
        else{
            if(N%26!=0){
                N--;
                count++;
            }
            else if(N%26==0&&count==0)
            {
                s+='z';
                N-=1;
               N/=26;

            }
            else{
                s+=arr[count-1];
                N=N/26;
                count=0;
            }
        }
    }
    if(N==26)
        s+='a';
    else if(N>=1&&N<26) {



        s += arr[N-1];
    }
reverse(s.begin(),s.end());
cout<<s;

    return 0;
}
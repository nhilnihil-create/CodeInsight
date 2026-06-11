#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int a[100000];
int ans[100000];
int main()
{
    cin>>s;
    int N=s.length();
    int count_r=0,count_l=0;
    int pos_r;
    for(int i=0;i<N;){
        while(s.at(i)=='R'){
            ++count_r;++i;
        }
        pos_r=i-1;
        while(i<N&&s.at(i)=='L'){
            ++count_l;++i;
        }
        ans[pos_r]=(count_r+count_l)/2;
        ans[pos_r+1]=count_r+count_l-ans[pos_r];
        if(count_r%2!=0)swap(ans[pos_r],ans[pos_r+1]);
        count_r=0;count_l=0;
    }
    for(int i=0;i<N;++i)cout<<ans[i]<<' ';
    return 0;
}
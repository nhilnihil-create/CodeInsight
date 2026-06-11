#include<iostream>
using namespace std;
int main()
{
    string str1,str2;
    unsigned int len_1,len_2,i,phase_1=0,phase_2=1;
    cin>>str1>>str2;
    for(len_1=0;str1[len_1]!='\0';len_1++)
    for(len_2=0;str2[len_2]!='\0';len_2++)
    if(len_1+1 == len_2) phase_1=1;
    for(i=0;i<len_1;i++){
        if(str1[i]!=str2[i]){
            phase_2=0;
            break;
        }
    }
    if(phase_1==1 && phase_2==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

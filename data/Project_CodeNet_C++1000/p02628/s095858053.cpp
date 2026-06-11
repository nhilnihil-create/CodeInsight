#include <iostream>
#include<vector>
using namespace std;

int main()
{
int size1=0,size2=0;
int num=0;
int mini=0;
vector<int>n;
int j=0;
cin>>size1>>size2;
for(int i=0;i<size1;i++){
  cin>>num;
    n.push_back(num);

}

 for(int i=1;i<size1;i++){
      int first=n[i];
    for (j=i ; j > 0&&first<n[j-1] ; j--){
        n[j] = n[j-1];}
        n[j] = first;

 }

for(int i=0;i<size2;i++){
        mini=mini+n[i];
}
cout<<mini;






    return 0;
}

#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int size1=0,num=0,count=0;
    cin>>size1;
    vector<int>n;

for(int i=0;i<size1;i++){
    cin>>num;
    n.push_back(num);

}
for(int i=0;i<n.size();i++){
    if(n[i]%2!=0&&i%2==0){count++;}
}

cout<<count;

    return 0;
}

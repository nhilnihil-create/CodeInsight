#include <iostream>
using namespace std;
int main()
{
    string s;
  	cin>>s;
  	if(s=="Sunny" || s=="sunny")	cout<<"Cloudy";
  	if(s=="Cloudy" || s=="cloudy")  cout<<"Rainy";
  	if(s=="Rainy" || s=="rainy")  cout<<"Sunny";
    cout<<endl;
    return 0;
}
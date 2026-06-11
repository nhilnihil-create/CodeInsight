#include <iostream>


using namespace std;

int main()
{
  string x;
  cin>>x;
   string Sunny,Cloudy,Rainy;
   if(x== "Sunny" )
   {
       cout<<"Cloudy"<<endl;
   }
    else if(x== "Cloudy" )
    {
        cout<<"Rainy"<<endl;
    }
   else if(x== "Rainy" ){
        cout<<"Sunny"<<endl;
    }

    return 0;
}

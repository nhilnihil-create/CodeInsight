#include <iostream>

using namespace std;

//Compiler version g++ 6.3.0

int main()

{

    char str[8];

    

    for(int i=0 ; i<6;i++)

    {

    	cin>> str[i];    }

    

    if(str[2]==str[3] && str[4]== str[5])

    cout<<"Yes"<<endl;

    else

    cout<<"No"<<endl;

}

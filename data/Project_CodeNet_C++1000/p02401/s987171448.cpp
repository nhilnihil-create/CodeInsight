#include<iostream>
 using namespace std;

int main(){


int a[10000] , b[10000] ;
char op[10000] ;
int x[10000]; 



 	for (int i=1; i<=10000; i=i+1 )
 	{
 	 cin >> a[i] >> op[i] >> b[i] ;

		if( op[i] == '?' )
 		{
 		break;
 		}else{
         }

                if ( op[i] == '+' ){
                cout<< a[i] + b[i] << endl; // �a
                } else if ( op[i] == '-' ){
                cout<< a[i] - b[i] << endl; // ��
                } else if ( op[i] == '*' ){
                cout<< a[i] * b[i] << endl; // ��
                } else if ( op[i] == '/' ){
                cout<< a[i] / b[i] << endl; // ��
                } else {
                break ; // �ُ�I��
                }


 	}

 return 0;
 }




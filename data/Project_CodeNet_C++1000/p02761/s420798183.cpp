/// RIFAT SHARIAR SAKIL
/// SOFTWARE ENGINEERING, SUST
/// 2019831024

#include<bits/stdc++.h>
#define ll long long
#define t INT_MAX
using namespace std;
int main()
{
   // while(1)
  //  {
        int n,m,i;
    cin >> n >> m;
   // int a[n]={0},mx[3]={t,t,t};
    set <int> s1,s2,s3;
    set <int>::iterator it,ti,iu;
    for(i=0;i<m;i++)
    {
        int s,c;
        cin >> s >> c;
        /*if(s==1)
        {
            if(c && c<mx[s-1])
            {
                mx[s-1]= c;
                a[s-1] = c;
            }
        }
        else if( c<mx[s-1] )
        {
            mx[s-1] = c;
            a[s-1] = c;
        }*/
        if(s==1) s1.insert(c);
        else if(s==2)s2.insert(c);
        else s3.insert(c);
    }
    if(s1.size()>1 || s2.size()>1 || s3.size()>1 ) {cout << "-1";return 0;}
    if(s1.size()==0 && n>1){cout << "1";}
    else if(s1.size() && *(s1.begin())==0 && n>1){cout << "-1";return 0;}
    else if(s1.size()==0) cout << "0";
    else cout << *(s1.begin());


     //   cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
          ti = s2.begin();
         if(n>=2)
         {
            // if(*it==0 && )
             if(s2.size()==0) cout << "0";
              //  {cout << "-1";return 0;}
             else cout << *ti;
         }
        iu = s3.begin();
        if(n==3)
        {
            if(s3.size()==0)cout << "0";
            else cout << *iu;
        }


      //  cout << endl;
  //  }



}

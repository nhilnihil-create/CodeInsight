    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
      int k;cin>>k;
      string s;cin>>s;string temp="";
      int l=s.length();
      if(l<=k) cout<<s;
      else 
      {
        for(int i=0;i<k;i++)
        {
          temp+=s[i];
        }
        temp+="...";
        cout<<temp;
      }
      return 0;
    }
#include<bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;
typedef pair<double,double> P;
vector<P> ans;
void kohho(P b,P e,int c){
  //cout << b.X << " " << b.Y << " " <<e.X<<" "<<e.Y<<endl;
  if(!c)return;
  P s,u,t;
  s.X=(-b.X+e.X)/3.0+b.X;
  s.Y=(-b.Y+e.Y)/3.0+b.Y;
  t.X=s.X+s.X-b.X;
  t.Y=s.Y+s.Y-b.Y;
  u.X=t.X-s.X;
  u.Y=t.Y-s.Y;
  double st = u.X;
  u.X = u.X*cos(60.0*M_PI/180.0)-u.Y*sin(60.0*M_PI/180.0);
  u.Y = st*sin(60.0*M_PI/180.0)+u.Y*cos(60.0*M_PI/180.0);
  u.X+=s.X;
  u.Y+=s.Y;
  
  kohho(b,s,c-1);
  cout << s.X << " " << s.Y << endl;
  kohho(s,u,c-1);
  cout << u.X << " " << u.Y << endl;
  kohho(u,t,c-1);
  cout << t.X << " " << t.Y << endl;
  kohho(t,e,c-1);
  ans.push_back(s);
  ans.push_back(t);
  ans.push_back(u);
}
  
int main(){
  int n;
  cin >> n;

  P st,en;
  st.X=0;
  st.Y=0;
  en.X=100.0;
  en.Y=0;
  ans.push_back(st);
  ans.push_back(en);
  cout << st.X <<" "<< st.Y << endl;
  kohho(st,en,n);
  sort(ans.begin(),ans.end());
  // for(int i=0;i<ans.size();i++){
  // printf("%.10f %.10f\n",ans[i].X,ans[i].Y);
  //}
  cout << en.X << " " << en.Y << endl;
  return 0;
}
 
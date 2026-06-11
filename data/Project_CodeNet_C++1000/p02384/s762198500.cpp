#include<iostream>

using namespace std;

class dice
{
public:
  int d[6];
  int t;
  int n;
  int e;
  int s;
  int w;
  int b;
  
  dice();
  int init();
  int move(char c);
  int runCmd(string cmd);
  int toTop(int x);
  int toFront(int x);
  int top();
  int right();
};

dice::dice()
{
  t = 0;
  n = 4;
  e = 2;
  s = 1;
  w = 3;
  b = 5;
}

int dice::init()
{
  for(int i = 0; i < 6; i++ )
    {
      cin >> d[i];
    }
  return 0;
}

int dice::move(char c)
{
  int tmp;
  
  if ( c == 'E' )
    {
      tmp = t;
      t = w;
      w = b;
      b = e;
      e = tmp;
    }
  else if ( c == 'N' )
    {
      tmp = t;
      t = s;
      s = b;
      b = n;
      n = tmp;
    }
  else if ( c == 'S' )
    {
      tmp = t;
      t = n;
      n = b;
      b = s;
      s = tmp;
    }
  else if ( c == 'W' )
    {
      tmp = t;
      t = e;
      e = b;
      b = w;
      w = tmp;
    }

  return 0;
}

int dice::runCmd(string cmd)
{
  for ( int i = 0; i < (int)cmd.size(); i++ )
    move( cmd[i] );

  return 0;
}

int dice::toTop(int x)
{
  int pt;
  
  for ( int i = 0; i < 6; i++ )
    {
      if ( d[i] == x )
        {
          pt = i;
          break;
        }
    }
  
  if ( n == pt )
    {
      runCmd( "S" );
    }
  else if ( e == pt )
    {
      runCmd( "W" );
    }
  else if ( s == pt )
    {
      runCmd( "N" );
    }
  else if ( w == pt )
    {
      runCmd( "E" );
    }
  else if ( b == pt )
    {
      runCmd("NN");
    }

  return 0;
}

int dice::toFront(int x)
{
  int pt;
  
  for ( int i = 0; i < 6; i++ )
    {
      if ( d[i] == x )
        {
          pt = i;
          break;
        }
    }
  
  if ( n == pt )
    {
      runCmd( "ESWESW" );
    }
  else if ( e == pt )
    {
      runCmd( "NWS" );
    }
  else if ( w == pt )
    {
      runCmd( "ESW" );
    }
}

int dice::top()
{
  cout << d[t] << endl;
  return 0;
}

int dice::right()
{
  cout << d[e] << endl;
  return 0;
}

int main()
{
  int n, t, f;
  dice d;
  
  d.init();

  cin >> n;

  for ( int i = 0; i < n; i++ )
    {
      cin >> t >> f;
  
      d.toTop(t);
      d.toFront(f);
      d.right();
    }

  return 0;
}